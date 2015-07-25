# Script for checking an implementation of intsafe.h to make sure it
# at least has the functions specified in Microsoft's documentation.

cd `dirname $0`/..

if [ -z "$VER" ]
then
    VER=proposed
fi
echo "intsafe version: $VER"

FUNC_NAMES=($(<test/function_names.txt))
for func in "${FUNC_NAMES[@]}"
do
    if [ -z "$func" ]
    then
        continue
    fi
    grep -r $func $VER
done
