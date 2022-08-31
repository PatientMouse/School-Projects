"gst CheckingAccount.st"
"Andrew Gerber"

"Smalltalk CheckingAccount class"
"basef off of pub/sum/smalltalk/sum.st"

Account subclass: CheckingAccount [

    CheckingAccount class [
        new: n [
            ^super new init: n.
        ]
    ]
  
    "Init takes a name"
    init: n [
        number:=n
        
    ]
    "Sets the customer parent varible to c"
    setCustomer: c [
        customer:=c.
    ]
    "Sets the balance to b"
    setBalance: b [
        balance:=b.
    ]

    "Accrue, FROM NOTES"
    accrue: rate [
        ^self subclassResponsibility
    ]

]