# Script for checking an implementation of intsafe.h to make sure it
# at least has the functions specified in Microsoft's documentation.

cd `dirname $0`

if [ -z "$VER" ]
then
    VER=proposed
fi

count=0
FUNC_NAMES=($(<function_names.txt))
echo > missing_functions.txt
for func in "${FUNC_NAMES[@]}"
do
    if [ -z "$func" ]
    then
        continue
    fi
    func="${func//$'\r'}"
    (grep -e "\b${func}\b" -r ../$VER 2>&1 > /dev/null)
    if [ $? -ne 0 ]
    then
        count=$((count + 1))
        echo "missing $func"
        echo $func >> missing_functions.txt
    fi
done

echo "missing function count: $count"
