/*
Package distanceconv performs M, MI, FT distance computations.
*/

package distanceconv

import (
	"fmt"
	"math"
)

type Meter float64
type Mile float64
type Feet float64
type LightYear float64

func (m Meter) String() string      { return fmt.Sprintf("%gm", m) }
func (mi Mile) String() string      { return fmt.Sprintf("%gmi", mi) }
func (ft Feet) String() string      { return fmt.Sprintf("%gft", ft) }
func (ly LightYear) String() string { return fmt.Sprintf("%gly", ly) }

var (
	EarthToMoon               Meter     = Meter(384400 * math.Pow10(3))
	EarthToSun                Meter     = Meter(149.71 * math.Pow10(3) * math.Pow10(6))
	EarthToMars               Meter     = Meter(271.96 * math.Pow10(3) * math.Pow10(6))
	EarthToAndromeda          LightYear = LightYear(2.537 * math.Pow10(6))
	EarthToObservableUniverse LightYear = LightYear(46.5 * math.Pow10(9))
)

func MiToM(mi Mile) Meter {
	return Meter(1609.34 * mi)
}

func MToMi(m Meter) Mile {
	return Mile(0.00062137 * m)
}

func FtToM(ft Feet) Meter {
	return Meter(0.3048 * ft)
}

func MToFt(m Meter) Feet {
	return Feet(3.28084 * m)
}

func LyToM(ly LightYear) Meter {
	return Meter(9.46 * math.Pow10(15))
}

func MToLy(m Meter) LightYear {
	return LightYear(1.057 * math.Pow10(-16))
}
