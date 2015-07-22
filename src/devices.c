#include <venus.h>

device *devices;
DWORD current_devices;

void init_devices(DWORD devnum)
{
	devices = (device *)malloc(devnum * sizeof(device));
	
	if(devices == NULL) {
		printf("cannot allocate memory for devices...\n");
		exit(1);
	}
	
	current_devices = 0;
}

void install_device(char *dev_name)
{
	char *error;
	char dev_path[64];
	
	if(current_devices >= DEFAULT_DEV_NUM) {
		printf("reached max devices\n");
		exit(1);
	}
	
	strcpy(devices[current_devices].dev_name, dev_name);
	sprintf(dev_path, "devices/%s.so", dev_name);
	devices[current_devices].dev_handler = dlopen(dev_path, RTLD_LAZY);
	
	if(!devices[current_devices].dev_handler) {
		fputs(dlerror(), stderr);
        exit(1);
    }

	devices[current_devices].init_func = dlsym(devices[current_devices].dev_handler, "init");
	devices[current_devices].quit_func = dlsym(devices[current_devices].dev_handler, "quit");
    devices[current_devices].get_func = dlsym(devices[current_devices].dev_handler, "get");
    devices[current_devices].set_func = dlsym(devices[current_devices].dev_handler, "set");
    devices[current_devices].send_func = dlsym(devices[current_devices].dev_handler, "send");
    devices[current_devices].exec_func = dlsym(devices[current_devices].dev_handler, "exec");
    
    if((error = dlerror()) != NULL) {
		fputs(error, stderr);
        exit(1);
	}
	
	devices[current_devices].init_func();
	current_devices++;
}

void free_devices()
{
	int i;
	
	for(i = 0; i < current_devices; i++) {
		devices[i].quit_func();
		dlclose(devices[i].dev_handler);
	}
}

CELL device_get(CELL dev_id, CELL addr)
{
	return devices[dev_id].get_func(addr);
}

CELL device_set(CELL dev_id, CELL addr, CELL value)
{
	return devices[dev_id].set_func(addr, value);
}

CELL device_exec(CELL dev_id, CELL value) 
{
	return devices[dev_id].exec_func(value);
}

CELL device_send(CELL dev_id, CELL addr, CELL sz)
{
	return devices[dev_id].send_func(get_cell_physaddr(addr), sz);
}
	
	
	
	
