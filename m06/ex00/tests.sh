#!/bin/bash

validateTrue() {
	let "TESTNBR++"
	local ARGUMENT=$1
	if [ $VERBOSE == 1 ]; then
		echo " "
		echo "  [$TESTNBR]testing $ARGUMENT "
		$COMMAND $ARGUMENT $ARGUMENT2
	else
		echo -n "  [$TESTNBR]testing $ARGUMENT "
		$COMMAND $ARGUMENT $ARGUMENT2 > /dev/null 2>&1
	fi
	if [ $? != 0 ]; then
		local EXITCODE=$?
		echo -e "---------\xE2\x9D\x8C"
		# echo "ERROR AT TEST NUMBER [$TESTNBR]"
		# exit $EXITCODE
	else
		echo -e "---------\xE2\x9C\x85"
	fi
}

validateFalse() {
	let "TESTNBR++"
	local ARGUMENT=$1
	local ARGUMENT2=$2
	if [ $VERBOSE == 1 ]; then
		echo " "
		echo "  [$TESTNBR]testing $ARGUMENT, $ARGUMENT2 "
		$COMMAND $ARGUMENT $ARGUMENT2
	else
		echo -n "  [$TESTNBR]testing $ARGUMENT, $ARGUMENT2 "
		$COMMAND $ARGUMENT $ARGUMENT2 > /dev/null 2>&1
	fi
	if [ $? == 0 ]; then
		local EXITCODE=$?
		echo -e "---------\xE2\x9D\x8C"
		# echo "ERROR AT TEST NUMBER [$TESTNBR]"
		# exit $EXITCODE
	else
		echo -e "---------\xE2\x9C\x85"
	fi
}

make
if [[ $? != 0 ]]; then
	echo "COMPILATION ERROR!"
	exit 1
fi
clear

echo "######### STARTING TESTS ###############"

TESTNBR=0
COMMAND="./convert"
VB1="verbose"
VB2="VERBOSE"

if [[ "$1" == "$VB1" ]]; then
	VERBOSE=1
elif [[ "$1" == "$VB2" ]]; then
	VERBOSE=1
else
	VERBOSE=0
fi

#testing floats
	#TODO: implement max/min
echo ">>>>>>>>>>>>>>>>>>TESTING FLOATS"
validateTrue "nanf"
validateTrue "+inff"
validateTrue "-inff"
validateTrue "42.042f"
validateTrue "0.042f"
validateTrue "42f"
validateTrue "0f"
validateTrue "0.0f"
validateTrue "-42.042f"
validateTrue "-0.042f"
validateTrue "-42f"
validateTrue "-0f"
#testing doubles
	#TODO: implement max/min
echo ">>>>>>>>>>>>>>>>>>TESTING DOUBLES"
validateTrue "nan"
validateTrue "+inf"
validateTrue "-inf"
validateTrue "42.042"
validateTrue "0.042"
validateTrue "0.0"
validateTrue "-42.042"
validateTrue "-0.042"
validateTrue "123.123"

#testing ints
echo ">>>>>>>>>>>>>>>>>>TESTING INTS"
validateTrue "123"
validateTrue "42";
validateTrue "-42";
validateTrue "-0";
validateTrue "0";
#testing chars
echo ">>>>>>>>>>>>>>>>>>TESTING CHARS"
validateTrue "a"
validateTrue "z"
validateTrue "A"
validateTrue "Z"
validateTrue "f"

#testing errors
echo ">>>>>>>>>>>>>>>>>>TESTING ERRORS"
validateFalse "nan" "test"
validateFalse ""
validateFalse ".123f"
validateFalse ".f"
validateFalse "123.123ff"
validateFalse "1.f"
validateFalse "123.123f123"
validateFalse "123.f"
validateFalse "ff"
validateFalse "123.f"



echo "FULLY RAN ALL TESTS!"
