//Author andrew Gerber
//based on person

package Customer

// import . "fmt"

type ICustomer interface {
	Name() string
	String() string
}

type Customer struct {
	name string
}

func NewCustomer(name string) (c *Customer) {
	c = new(Customer)
	c.Init(name)
	return
}

func (c *Customer) Init(name string) {
	c.name = name
}

func (c *Customer) toString() string {
	return c.name
}
