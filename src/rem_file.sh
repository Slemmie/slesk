# remove potentially existing file

if [ -f "$1" ]; then
	rm "$1"
fi
