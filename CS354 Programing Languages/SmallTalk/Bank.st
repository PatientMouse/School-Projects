"gst Bank.st"
"Andrew Gerber"

"Smalltalk Bank Class"
"basef off of pub/sum/smalltalk/sum.st and saving bank.java"

Object subclass: Bank [
"Bank is a class that represents a bank"

"set inistance vriables"
|accounts|



Bank class [
        new [
            ^super new init
        ]    
    ]

"init function for bank takes no parameters"
init [
    accounts:= Array new: 10
]

"Add an account to the bank"
add: accountIN[
    accounts add: accountIN
]

"Print bank"
toString[
    "accounts do: [ ^account toString ]"
]

"Primary accrue interest function"
accrue: rate [
    "accounts do: [:account|
        account accrue: rate
    ]"
]




]


"This main is based off of sum.st and bank,java"

"Create bank and customer object"
|Bank| bank := Bank new.
|Customer| cust := Customer new: 'Andrew Gerber'.

"make a CheckingAccount and set its name in the init, then call helpers to set customers and the balance"
|CheckingAccount| ca:= (CheckingAccount new: 'CHK0001').
ca setCustomer: cust.
ca setBalance: 1000.

"make a SavingAccount and set its name in the init, then call helpers to set customers and the balance"
|SavingAccount| sa:= (SavingAccount new: 'SVV0001').
sa setCustomer: cust.
sa setBalance: 2000.


"Acrrue"
bank accrue: 0.2.

"Print NOT WORKING"
"bank toString."

