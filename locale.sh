arg=$1

case $arg in
0)
	lang="en_us"
	;;
1)
	lang="fr_fr"
	;;
esac

echo Getting files from $lang
cp -r ./locale/$lang/ .
