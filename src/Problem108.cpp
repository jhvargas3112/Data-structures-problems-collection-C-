/*
 * Problem108.cpp
 *
 *  Created on: 1 feb. 2021
 *  Author: Jhonny Vargas Paredes
 *  URL: https://www.aceptaelreto.com/problem/statement.php?id=108&cat=13
 */


#include <iostream>
#include <stdlib.h>

using namespace std;

struct categorySale {
	char category;
	string categoryName;
	int soldUnits = 0;
	double profit = 0;
};

const int NUM_CATEGORIES = 5;

double calculateCategoriesSalesAverage(const categorySale categoriesSales[]) {
	int totalSoldUnits = 0;
	double totalProfit = 0;

	for (int i = 0; i < NUM_CATEGORIES; i++) {
		totalSoldUnits += categoriesSales[i].soldUnits;
		totalProfit += categoriesSales[i].profit;
	}

	return totalProfit / totalSoldUnits;
}

double calculateLunchesSalesAverage(const categorySale categoriesSales[]) {
	return categoriesSales[1].profit / categoriesSales[1].soldUnits;
}

categorySale getMaxSalesCategory(const categorySale categoriesSales[]) {
	double max = categoriesSales[0].profit;
	categorySale maxSalesCategory = categoriesSales[0];

	int i = 0;

	while (i < NUM_CATEGORIES) {
		if (categoriesSales[i].profit > max) {
			max = categoriesSales[i].profit;
			maxSalesCategory = categoriesSales[i];
		}

		i++;
	}

	return maxSalesCategory;
}

categorySale getMinSalesCategory(const categorySale categoriesSales[]) {
	double min = categoriesSales[0].profit;
	categorySale minSalesCategory = categoriesSales[0];

	int i = 0;

	while (i < NUM_CATEGORIES) {
		if (categoriesSales[i].profit < min) {
			min = categoriesSales[i].profit;
			minSalesCategory = categoriesSales[i];
		}

		i++;
	}

	return minSalesCategory;
}

bool isThereATieForTheCategories(const categorySale categoriesSales[], const categorySale maxSalesCategory, const categorySale minSalesCategory) {
	bool categoriesTie = true;

	int i = 0;

	while (i < NUM_CATEGORIES) {
		categoriesTie = categoriesTie || (categoriesSales[i].profit == maxSalesCategory.profit || categoriesSales[i].profit == minSalesCategory.profit);

		i++;
	}

	return categoriesTie;
}

void salesInput(categorySale categoriesSales[]) {
	char category;
	double paid;

	do {
		cin >> category >> paid;

		switch (category) {
		case 'D':
			categoriesSales[0].soldUnits++;
			categoriesSales[0].profit += paid;
			break;
		case 'A':
			categoriesSales[1].soldUnits++;
			categoriesSales[1].profit += paid;
			break;
		case 'M':
			categoriesSales[2].soldUnits++;
			categoriesSales[2].profit += paid;
			break;
		case 'I':
			categoriesSales[3].soldUnits++;
			categoriesSales[3].profit += paid;
			break;
		case 'C':
			categoriesSales[4].soldUnits++;
			categoriesSales[4].profit += paid;
			break;
		}
	} while (category != 'N' && paid != 0);

	cout << '\n';
}

int main(void) {
	std::ios::sync_with_stdio(false);

	categorySale categoriesSales[NUM_CATEGORIES];

	categoriesSales[0] = {'D', "DESAYUNOS"};
	categoriesSales[1] = {'A', "COMIDAS"};
	categoriesSales[2] = {'M', "MERIENDAS"};
	categoriesSales[3] = {'I', "CENAS"};
	categoriesSales[4] = {'C', "COPAS"};

	salesInput(categoriesSales);

	categorySale maxSalesCategory = getMaxSalesCategory(categoriesSales);
	categorySale minSalesCategory = getMinSalesCategory(categoriesSales);

	double categoriesSalesAverage = calculateCategoriesSalesAverage(categoriesSales);
	double lunchesSalesAverage = calculateLunchesSalesAverage(categoriesSales);

	bool categoriesTie = isThereATieForTheCategories(categoriesSales, maxSalesCategory, minSalesCategory);

	if (categoriesTie && lunchesSalesAverage > categoriesSalesAverage) {
		cout << maxSalesCategory.categoryName << "#EMPATE" << "#SI";
	} else if (categoriesTie && lunchesSalesAverage <= categoriesSalesAverage) {
		cout << maxSalesCategory.categoryName << "#EMPATE" << "#NO";
	} else if (!categoriesTie && lunchesSalesAverage > categoriesSalesAverage) {
		cout << maxSalesCategory.categoryName << minSalesCategory.categoryName << "#SI";
	} else if (!categoriesTie && lunchesSalesAverage <= categoriesSalesAverage) {
		cout << maxSalesCategory.categoryName << minSalesCategory.categoryName << "#NO";
	}

	return 0;
}
