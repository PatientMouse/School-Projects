//Andrew Gerber
package account

import (
	"fmt"

	. "./customer"
)

type IAccount interface {
	// Balance()
	Deposit(amount float64)
	Withdraw(amount float64)
	ToString() string
	Accrue()
}

type Account struct {
	number   int
	customer Customer
	balance  float64
}

func (a *Account) Accrue() {
}

func NewAccount(number int, cust Customer, balance float64) (a *Account) {
	a = new(Account)
	a.Init(number, cust, balance)
	return
}

func (a *Account) Init(number int, cust Customer, balance float64) {
	a.number = number
	a.customer = cust
	a.balance = balance
}

// func Balance(a *Account) float64 {
// 	return a.balance
// }

func (a *Account) Deposit(amount float64) {
	a.balance += amount
}

func (a *Account) Withdraw(amount float64) {
	a.balance -= amount
}

func (a *Account) ToString() string {
	return fmt.Sprintf("%s"+", %f"+", %f", a.customer, a.number, a.balance)
}
