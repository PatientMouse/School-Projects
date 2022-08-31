#!/bin/awk -f
# Andrew Gerber
# Awk cvs to html converter
#based on skeleton.html format

BEGIN {
    print "<html><head><title>Public Building Permit Records</title></head><body>"
    print "<h1>Public Building Permit Records</h1>"
    print "<table border=1>"
    print "<tr><th>Andrew Gerber</th>></tr>"
    print "<tr><th>Date</th><th>Subdivision</th><th>Lot #</th><th>Block #</th><th>Value $</th></tr>"
    FPAT = "([^,]+)|(\"[^\"]+\")" #https://www.gnu.org/software/gawk/manual/html_node/Splitting-By-Content.html
}

#IssueDate,BldgPermitNum,Description,SquareFootage,SubNameOrTwnRngSec,LOT,BLOCK,Value
#Date is in the first column, $1
#subdivision is in the fifth column, $5
#lot is in the sixth column, $6
#block is in the seventh column, $7
#value is in the eighth column, $8


#https://www.gnu.org/software/gawk/manual/html_node/Splitting-By-Content.html
#check if the description is a single family home
{
    IGNORECASE= 1 #need this to check for spelling error
    if($3 ~ "single"){ #https://linuxhint.com/conditional_statement_awk_command/ & https://www.unix.com/unix-for-advanced-and-expert-users/156232-awk-line-contains-someting-field.html
    # print $3
    print "<tr><td>" $1 "</td><td>" $5 "</td><td>" $6 "</td><td>" $7 "</td><td>" $8 "</td></tr>"
    }
}

END {
    print "</table>"
    print "</body></html>"
}