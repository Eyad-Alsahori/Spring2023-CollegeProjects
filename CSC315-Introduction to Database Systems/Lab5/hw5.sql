SELECT CategoryName
     , COUNT(*) AS CategoryCount
     , ROUND(AVG(UnitPrice), 2) AS AvgUnitPrice
     , MIN(UnitPrice) AS MinUnitPrice
     , MAX(UnitPrice) AS MaxUnitPrice
     , SUM(UnitsOnOrder) AS TotalUnitsOnOrder
FROM Product INNER JOIN Category on CategoryId = Category.Id
GROUP BY CategoryId
HAVING CategoryCount > 10
ORDER BY CategoryId;


-- Beverages|12|37.98|4.5|263.5|60
-- Condiments|12|23.06|10|43.9|170
-- Confections|13|25.16|9.2|81|180
-- Seafood|12|20.68|6|62.5|120
