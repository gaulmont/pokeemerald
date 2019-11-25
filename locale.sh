arg=$1

case $arg in
0)
	lang="us"
	;;
1)
	lang="fr"
	;;
esac

echo Getting files from $lang
cp -r ./locale/$lang/ .
