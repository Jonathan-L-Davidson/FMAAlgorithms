using System;
using System.Collections.Generic;
using System.Linq;


//Scenario 2: Space Mining Game Problem
//
//· You are in command of an inter - galactic mining vessel, which has to pick up loads from a series of 5 planets in a solar system.
//
//· You can assume that the planets are geo - stationary with respect to each other and so maintain a fixed distance in space.
//
//· The distances are stored in the table below and are in millions of km.
//
//
//
//· The Fuel Consumption of the spaceship is based on the loading of the spaceship(OK in space I know it’s not really the case but …..!!).
//· The cost of the depletion of Dylithium crystal is 25 intergalactic currency units per metric tonne per million kms.
//. 25 * ton * kms
//· The loads picked up at each planet are as follows and assume that the spacecraft can fit all the loads inside its hold.
//	Alpha	20 Tons
//	Beta	40 Tons
//	Gamma	70 Tons
//	Delta	10 Tons
//	Epsilon 30 Tons
//
//	Using this information what is the cheapest route ? State any assumptions made.
//	0			1		2		3		4
//				BETA	GAMMA	DELTA	EPSILON
//	ALPHA		10		15		12		20
//
//	BETA		-		12		25		14
//
//	GAMMA		-		-		16		28
//
//	DELTA		-		-		-		17



//Task 1:
//
//Draw the graph describing the scenario. - DONE

//Task 2:
//
//Use a brute - force approach to enumerate all possible combinations required, how many different combinations would need to be considered
//Use the brute force approach to affirm an optimal solution against which to compare the solutions obtained using other approaches?
//Explain why this is considered an unreasonable algorithm.

// Reasons this is trash:
// - Brute Force will always be the worst case situation for the algorithm as it computes EVERY possible outcome.
// - 

// Solution to program this:
// Get all permutations (Possible combinations) of travelling methods. Store into list.
// for every method of travel, calculate the cost. Store it into another list.
// output travel list.

// Problem: Getting permutations. Rest of the calculation can be easy.






namespace CSharp {


	public struct Planet {
		public int[,] planetLink;
		public int load;
	};

	// Referenced from https://stackoverflow.com/questions/1952153/what-is-the-best-way-to-find-all-combinations-of-items-in-an-array
	// Pengyang (2014)
	public static class LINQ {
		public static IEnumerable<IEnumerable<T>> Permute<T>(this IEnumerable<T> sequence) {
			if (sequence == null) {
				yield break;
			}

			var list = sequence.ToList();

			if (!list.Any()) {
				yield return Enumerable.Empty<T>();
			} else {
				var startingElementIndex = 0;

				foreach (var startingElement in list) {
					var index = startingElementIndex;
					var remainingItems = list.Where((e, i) => i != index);

					foreach (var permutationOfRemainder in remainingItems.Permute()) {
						yield return permutationOfRemainder.Prepend(startingElement);
					}

					startingElementIndex++;
				}
			}
		}
	}

	public class Program {


		static string GetPlanet(int i) {
			string planet = "";
			switch (i) {
				case 0:
					planet = "Alpha";
					break;
				case 1:
					planet = "Beta";
					break;
				case 2:
					planet = "Gamma";
					break;
				case 3:
					planet = "Delta";
					break;
				case 4:
					planet = "Epsilon";
					break;
			}

			return planet;
		}

		static void Main(string[] args) {

			Planet alpha;       // 0
			alpha.load = 20;
			alpha.planetLink = new int[,] { { 1, 10 }, { 2, 15 }, { 3, 12 }, { 4, 20 } };

			Planet beta;        // 1
			beta.load = 40;
			beta.planetLink = new int[,] { { 0, 10 }, { 2, 12 }, { 3, 25 }, { 4, 14 } };

			Planet gamma;       // 2
			gamma.load = 70;
			gamma.planetLink = new int[,] { { 0, 15 }, { 1, 12 }, { 3, 16 }, { 4, 28 } };

			Planet delta;       // 3
			delta.load = 10;
			delta.planetLink = new int[,] { { 0, 12 }, { 1, 25 }, { 2, 16 }, { 4, 17 } };

			Planet epsilon;     // 4
			epsilon.load = 30;
			epsilon.planetLink = new int[,] { { 0, 20 }, { 1, 14 }, { 2, 28 }, { 3, 17 } };

			List<int> planetsNumeroDos = new List<int> { 0, 1, 2, 3, 4 };

			List<Planet> planets = new List<Planet> { alpha, beta, gamma, delta, epsilon };

			var permutedResults = LINQ.Permute<int>(planetsNumeroDos).ToList();


			Console.WriteLine("Bruteforce START:");
			for (int i = 0; i < permutedResults.Count; i++) {
				var path = permutedResults[i].ToList();

				int distance = 0;
				int totalLoad = 0;

				string planetPath = "";
				for (int j = 0; j < path.Count - 1; j++) { // - 1 we dont need to calculate the last int as it will go out of bounds.

					totalLoad += planets[path[j]].load;

					Planet planetA = planets[path[j]];
					Planet planetB = planets[path[j + 1]];

					for (int k = 0; k < 4; k++) {
						if (path[j + 1] == planetA.planetLink[k, 0]) {
							distance += planetA.planetLink[k, 1];
						}
					}

					planetPath += (j > 0 ? " > " : "") + GetPlanet(path[j]);
				}


				Console.WriteLine("\nPermutable Result " + (i + 1) + ":\n" + "	Planet " + planetPath + " > " + GetPlanet(path[path.Count - 1]) + "\n" + "	Distance: " + distance + "\n" + "	Load:" + totalLoad + "\n" + "			Total Cost: " + (25 * totalLoad * distance));
			}
		}
	}
}
