# Test file for "Lab3"


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n

test "PINA: 0x11 => PORTC: 0x60"
setPINA 0x11
continue 5
expectPORTC 0x60
checkResult

test "PINA: 0x34 => PORTC: 0xB0"
setPINA 0x34
continue 5
expectPORTC 0xB0
checkResult

test "PINA: 0x75 => PORTC: 0x38"
setPINA 0x75
continue 5
expectPORTC 0x38
checkResult

test "PINA: 0x38 => PORTC: 0xBC"
setPINA 0x38
continue 5
expectPORTC 0xBC
checkResult

test "PINA: 0x3A => PORTC: 0xBE"
setPINA 0x3A
continue 5
expectPORTC 0xBE
checkResult

test "PINA: 0x3E => PORTC: 0xBF"
setPINA 0x3E
continue 5
expectPORTC 0xBF
checkResult

set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n