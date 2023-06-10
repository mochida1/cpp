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
clear

echo "######### STARTING TESTS ###############"
echo "testing name literals"
# {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"}

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


validateFalse "nan" "test"
validateTrue "nan"
validateTrue "+inf"
validateTrue "-inf"
validateTrue "nanf"
validateTrue "+inff"
validateTrue "-inff"
validateTrue "a"
validateTrue "z"

echo "FULLY RAN ALL TESTS!"
