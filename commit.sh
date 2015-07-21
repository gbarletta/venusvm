cd src
sh clean.sh
cd ..
git add --all .
git commit -m "$1"
git push origin master
