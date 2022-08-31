//amndrew Gerber
package account

import (
	// . "./account"
	. "./customer"
)

type ISaving interface {
	IAccount
	accrue()
}

type Saving struct {
	Account
	// number   int
	// customer Customer
	// balance  float64
	intrest float64
}

func NewSaving(number int, cust Customer, balance float64) (s *Saving) {
	s = new(Saving)
	s.Init(number, cust, balance)
	return
}

func (s *Saving) Init(number int, cust Customer, balance float64) {
	s.Account.Init(number, cust, balance)
	s.intrest = 0.0
}

func (s *Saving) accrue(rate float64) {
	s.intrest += s.balance * rate
	s.balance += s.balance * rate
}
