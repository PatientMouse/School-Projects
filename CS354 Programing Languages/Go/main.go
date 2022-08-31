//anmdrew gerber
package main

import (
	. "./account"
	. "./bank"
	. "./customer"
	// . "./saving"
)

func main() {
	var acc = map[*IAccount]IAccount{}
	var b = NewBank(acc)
	var c = NewCustomer("Ann")

	var check = NewChecking(01001, *c, 100.00)
	var save = NewSaving(01002, *c, 200.00)
	b.Add(check)
	b.Add(save)
	// b.accrue()
	b.ToString()
}
