/*
Package weightconv performs KG and LB weight computations.
NOTE: Here by `weight` I mean kgf. I.e. Kilogram-force.
*/

package weightconv

type Kilogram float64
type Pound float64

func LBToKG(lb Pound) Kilogram {
	return Kilogram(lb * 0.45)
}

func KGToLB(kg Kilogram) Pound {
	return Pound(kg * 2.2)
}
