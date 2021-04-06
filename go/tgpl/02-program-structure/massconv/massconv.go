/*
Package massconv performs KG and LB mass computations.
*/

package massconv

import "fmt"

type Kilogram float64
type Pound float64

func (kg Kilogram) String() string { return fmt.Sprintf("%gkg", kg) }
func (lb Pound) String() string    { return fmt.Sprintf("%glb", lb) }

func LBToKG(lb Pound) Kilogram {
	return Kilogram(lb * 0.45)
}

func KGToLB(kg Kilogram) Pound {
	return Pound(kg * 2.2)
}
