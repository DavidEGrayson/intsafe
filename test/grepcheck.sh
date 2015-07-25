# Script for checking an implementation of intsafe.h to make sure it
# at least has the functions specified in Microsoft's documentation.

cd `dirname $0`/..

if [ -z "$VER" ]
then
    VER=proposed
fi
echo "intsafe version: $VER"

count=0
FUNC_NAMES=($(<test/function_names.txt))
for func in "${FUNC_NAMES[@]}"
do
    if [ -z "$func" ]
    then
        continue
    fi
    (grep -r $func $VER 2>&1 > /dev/null)
    if [ $? -ne 0 ]
    then
        count=$((count + 1))
        echo "$count: missing $func"
    fi
done
