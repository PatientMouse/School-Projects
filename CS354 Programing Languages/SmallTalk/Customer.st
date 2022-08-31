"gst Customer.st"
"Andrew Gerber"

"Smalltalk Customer class"
"basef off of pub/sum/smalltalk/sum.st"

Object subclass: Customer [

    |name|

    Customer class [
        new: n [
            ^super new init: n
        ]    
    ]

    init: n [
        name:=n
    ]

    toString [
        ^name
    ]
]