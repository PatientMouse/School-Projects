//Andrew Gerber
package bank

import (
	"fmt"

	. "./account"
)

type IBank interface {
	Add()
	Accrue()
	ToString()
}

type Bank struct {
	accounts map[*IAccount]IAccount
}

func NewBank(acc map[*IAccount]IAccount) (b *Bank) {
	b = new(Bank)
	b.Init(acc)
	return
}

func (b *Bank) Init(acc map[*IAccount]IAccount) {
	b.accounts = acc
}

func (a *Bank) Add(account IAccount) {
	a.accounts[&account] = account
}

func (a *Bank) Accrue() {
	// for i := 0; i < a.accounts.size(); i++ {
	// 	accrue(a.accounts.get(i))
	// }
	for _, v := range a.accounts {
		go v.Accrue()
	}
}

func (a *Bank) ToString() {
	// for i := 0; i < a.accounts.size(); i++ {
	// 	a.accounts.get(i).toString()
	// }
	for _, v := range a.accounts {
		fmt.Println(v.ToString())
	}
}
