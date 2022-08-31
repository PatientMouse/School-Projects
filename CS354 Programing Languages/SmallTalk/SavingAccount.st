"gst SavingAccount.st"
"Andrew Gerber"

"Smalltalk SavingAccount subclass"
"basef off of pub/sum/smalltalk/sum.st and saving acct.java"

Account subclass: SavingAccount [
    "Set up the class variables"
    |interest|

    SavingAccount class [
        new: n [
            ^super new init: n.
        ]
    ]

    "Init takes a name"
    init: n [
        number:=n.
        interest:=0.0.
        
    ]
    "Sets the customer parent varible to c"
    setCustomer: c [
        customer:=c.
    ]
    "Sets the balance to b"
    setBalance: b [
        balance:=b.
    ]
    "Savings accrue"
    accrue: rate [
        interest:= balance*rate.
        balance:= balance*rate.
    ]

]