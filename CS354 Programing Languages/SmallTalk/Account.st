"gst Account.st"
"Andrew Gerber"

"Smalltalk Account class"
"based off of pub/sum/smalltalk/sum.st"

Object subclass: Account [
"Class variables"
    |number|
    |customer|
    |balance|

"Taken from notes"
    accrue: rate [
        ^self subclassResponsibility
    ]

"Return balce"
    balance [
        ^balance
    ]

"add amount to balance"
    deposit: amount [
        balance := balance + amount
    ]
"remover amount from balance"
    withdraw: amount [
        balance := balance - amount
    ]
    toString [
        ^'Account: ' , number , ' Customer: ' , customer , ' Balance: ' , balance
    ]
]