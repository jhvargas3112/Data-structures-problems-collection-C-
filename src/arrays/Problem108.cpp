/*
 * Problem108.cpp
 *
 *  Created on: 1 feb. 2021
 *  Author: Jhonny Vargas Paredes
 *  URL: https://www.aceptaelreto.com/problem/statement.php?id=108&cat=13
 */

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <malloc.h>

using namespace std;

struct categorySale {
  char categoryCode;
  string categoryName;
  int soldUnits;
  double profit;
};

bool comp(const categorySale i, const categorySale j) {
  return i.profit < j.profit;
}

double calculateCategoriesSalesAverage(
    const vector<categorySale> categoriesSales) {
  double totalProfit = categoriesSales[0].profit + categoriesSales[1].profit
      + categoriesSales[2].profit + categoriesSales[3].profit
      + categoriesSales[4].profit;

  int totalSoldUnits = categoriesSales[0].soldUnits
      + categoriesSales[1].soldUnits + categoriesSales[2].soldUnits
      + categoriesSales[3].soldUnits + categoriesSales[4].soldUnits;

  return totalProfit / totalSoldUnits;
}

double calculateLunchesSalesAverage(const categorySale categorySale) {
  return categorySale.profit / categorySale.soldUnits;
}

bool isThereATieForTheCategories(const vector<categorySale> categoriesSales,
                                 categorySale maxSalesCategory,
                                 categorySale minSalesCategory) {
  return categoriesSales[0].profit == categoriesSales[1].profit
      || categoriesSales[4].profit == categoriesSales[3].profit;
}

void salesInput(vector<categorySale> &categoriesSales) {
  char categoryCode;
  double paid;

  cin >> categoryCode >> paid;

  while (categoryCode != 'N' && paid != 0) {
    if (categoryCode == 'D') {
      categoriesSales[0].soldUnits++;
      categoriesSales[0].profit += paid;
    } else if (categoryCode == 'A') {
      categoriesSales[1].soldUnits++;
      categoriesSales[1].profit += paid;
    } else if (categoryCode == 'M') {
      categoriesSales[2].soldUnits++;
      categoriesSales[2].profit += paid;
    } else if (categoryCode == 'I') {
      categoriesSales[3].soldUnits++;
      categoriesSales[3].profit += paid;
    } else if (categoryCode == 'C') {
      categoriesSales[4].soldUnits++;
      categoriesSales[4].profit += paid;
    }

    cin >> categoryCode >> paid;
  }
}

int main(void) {
  std::ios::sync_with_stdio(false);

  vector<categorySale> categoriesSales;

  categoriesSales.push_back( { 'D', "DESAYUNOS", 0, 0 });
  categoriesSales.push_back( { 'A', "COMIDAS", 0, 0 });
  categoriesSales.push_back( { 'M', "MERIENDAS", 0, 0 });
  categoriesSales.push_back( { 'I', "CENAS", 0, 0 });
  categoriesSales.push_back( { 'C', "COPAS", 0, 0 });

  salesInput(categoriesSales);

  double categoriesSalesAverage = calculateCategoriesSalesAverage(
      categoriesSales);
  double lunchesSalesAverage = calculateLunchesSalesAverage(categoriesSales[1]);

  sort(categoriesSales.begin(), categoriesSales.end(), comp);

  categorySale maxSalesCategory = categoriesSales[4];
  categorySale minSalesCategory = categoriesSales[0];

  bool categoriesTie = isThereATieForTheCategories(categoriesSales,
                                                   maxSalesCategory,
                                                   minSalesCategory);

  if (categoriesTie && lunchesSalesAverage > categoriesSalesAverage) {
    cout << maxSalesCategory.categoryName << "#EMPATE" << "#SI" << endl;
  } else if (categoriesTie && lunchesSalesAverage <= categoriesSalesAverage) {
    cout << maxSalesCategory.categoryName << "#EMPATE" << "#NO" << endl;
  } else if (!categoriesTie && lunchesSalesAverage > categoriesSalesAverage) {
    cout << maxSalesCategory.categoryName << "#"
         << minSalesCategory.categoryName << "#SI" << endl;
  } else if (!categoriesTie && lunchesSalesAverage <= categoriesSalesAverage) {
    cout << maxSalesCategory.categoryName << "#"
         << minSalesCategory.categoryName << "#NO" << endl;
  }

  return 0;
}
