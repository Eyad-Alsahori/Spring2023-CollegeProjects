SELECT Region.Id AS RegionID, Region.RegionDescription, Employee.Id AS EmployeeID, Employee.FirstName, Employee.LastName, Employee.BirthDate
FROM Region 
LEFT JOIN Territory ON Region.Id = Territory.RegionId 
LEFT JOIN EmployeeTerritory ON Territory.Id = EmployeeTerritory.TerritoryId 
LEFT JOIN Employee ON EmployeeTerritory.EmployeeId = Employee.Id 
.....