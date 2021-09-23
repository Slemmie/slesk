# list all files in designated directory

where="./test/current_files"
if [ -f "$where" ]; then
	rm "$where"
fi
touch "$where"

for entry in "./test"/*.slcmmd
do
	"$entry" >> "$where"
done

echo "done"
