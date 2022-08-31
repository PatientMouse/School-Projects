//andrew Gerber
package account

import (
	// . "./account"
	. "./customer"
)

type IChecking interface {
	IAccount
	Balance()
	accrue()
}

type Checking struct {
	Account
	// number   int
	// customer Customer
	balance float64
}

func Balance(a *Checking) float64 {
	return a.balance
}

func NewChecking(number int, cust Customer, balance float64) (c *Checking) {
	c = new(Checking)
	c.Init(number, cust, balance)
	return
}

func (c *Checking) Init(number int, cust Customer, balance float64) {
	c.Account.Init(number, cust, balance)
}

func (c *Checking) accrue() {
}
