#include "pch.h"
#include <iostream>
using namespace std;

int calcFuelPerMass(int mass) {
	return (mass / 3) - 2;
}

int calcFuelPerModule(int mass) {
	int fuelModule = 0;
	int fuelNotAddedYet = calcFuelPerMass(mass);

	while (fuelNotAddedYet > 0) {
		fuelModule += fuelNotAddedYet;
		fuelNotAddedYet = calcFuelPerMass(fuelNotAddedYet);
	}
	return (fuelModule);
}

int main()
{
	int inputMass[] = { 103376,
		137623	,
		68454	,
		58133	,
		61015	,
		116383	,
		140128	,
		89136	,
		51424	,
		70304	,
		102774	,
		97379	,
		84863	,
		141276	,
		145979	,
		74658	,
		90303	,
		132694	,
		105438	,
		122561	,
		120795	,
		109609	,
		54936	,
		79878	,
		116519	,
		128765	,
		80686	,
		131652	,
		114035	,
		58722	,
		75602	,
		124920	,
		103586	,
		130337	,
		141906	,
		144110	,
		62813	,
		85774	,
		117135	,
		67600	,
		90364	,
		134128	,
		84632	,
		123047	,
		139372	,
		139431	,
		108657	,
		133502	,
		104636	,
		54475	,
		55535	,
		139116	,
		51999	,
		115467	,
		55044	,
		144280	,
		130497	,
		148374	,
		95362	,
		70575	,
		71362	,
		129912	,
		75244	,
		148802	,
		130203	,
		143033	,
		99100	,
		105136	,
		54304	,
		68539	,
		54939	,
		147045	,
		73775	,
		137798	,
		67588	,
		133550	,
		98726	,
		114631	,
		146613	,
		85018	,
		112986	,
		82081	,
		121413	,
		102317	,
		54296	,
		138394	,
		66992	,
		90480	,
		60262	,
		88846	,
		110095	,
		123471	,
		95487	,
		90791	,
		74350	,
		113870	,
		97581	,
		129236	,
		77417	,
		123082
	};
	int totalFuel = 0;

	for (const int &mass: inputMass){
		totalFuel += calcFuelPerModule(mass);

	}

    cout << totalFuel << endl;
}
