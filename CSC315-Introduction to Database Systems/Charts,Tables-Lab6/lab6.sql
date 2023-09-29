SELECT Employee.Id AS EmployeeID, Employee.FirstName, Employee.LastName, Employee.BirthDate, 
EmployeeTerritory.TerritoryId AS TerritoryID, Territory.TerritoryDescription, Region.Id AS RegionID, Region.RegionDescription
FROM Employee 
INNER JOIN EmployeeTerritory ON Employee.Id = EmployeeTerritory.EmployeeId 
INNER JOIN Territory ON EmployeeTerritory.TerritoryId = Territory.Id 
INNER JOIN Region ON Territory.RegionId = Region.Id;



-- 1|Nancy|Davolio|1980-12-08|06897|Wilton|1|Eastern
-- 1|Nancy|Davolio|1980-12-08|19713|Neward|1|Eastern
-- 2|Andrew|Fuller|1984-02-19|01581|Westboro|1|Eastern
-- 2|Andrew|Fuller|1984-02-19|01730|Bedford|1|Eastern
-- 2|Andrew|Fuller|1984-02-19|01833|Georgetow|1|Eastern
-- 2|Andrew|Fuller|1984-02-19|02116|Boston|1|Eastern
-- 2|Andrew|Fuller|1984-02-19|02139|Cambridge|1|Eastern
-- 2|Andrew|Fuller|1984-02-19|02184|Braintree|1|Eastern
-- 2|Andrew|Fuller|1984-02-19|40222|Louisville|1|Eastern
-- 3|Janet|Leverling|1995-08-30|30346|Atlanta|4|Southern
-- 3|Janet|Leverling|1995-08-30|31406|Savannah|4|Southern
-- 3|Janet|Leverling|1995-08-30|32859|Orlando|4|Southern
-- 3|Janet|Leverling|1995-08-30|33607|Tampa|4|Southern
-- 4|Margaret|Peacock|1969-09-19|20852|Rockville|1|Eastern
-- 4|Margaret|Peacock|1969-09-19|27403|Greensboro|1|Eastern
-- 4|Margaret|Peacock|1969-09-19|27511|Cary|1|Eastern
-- 5|Steven|Buchanan|1987-03-04|02903|Providence|1|Eastern
-- 5|Steven|Buchanan|1987-03-04|07960|Morristown|1|Eastern
-- 5|Steven|Buchanan|1987-03-04|08837|Edison|1|Eastern
-- 5|Steven|Buchanan|1987-03-04|10019|New York|1|Eastern
-- 5|Steven|Buchanan|1987-03-04|10038|New York|1|Eastern
-- 5|Steven|Buchanan|1987-03-04|11747|Mellvile|1|Eastern
-- 5|Steven|Buchanan|1987-03-04|14450|Fairport|1|Eastern
-- 6|Michael|Suyama|1995-07-02|85014|Phoenix|2|Western
-- 6|Michael|Suyama|1995-07-02|85251|Scottsdale|2|Western
-- 6|Michael|Suyama|1995-07-02|98004|Bellevue|2|Western
-- 6|Michael|Suyama|1995-07-02|98052|Redmond|2|Western
-- 6|Michael|Suyama|1995-07-02|98104|Seattle|2|Western
-- 7|Robert|King|1992-05-29|60179|Hoffman Estates|2|Western
-- 7|Robert|King|1992-05-29|60601|Chicago|2|Western
-- 7|Robert|King|1992-05-29|80202|Denver|2|Western
-- 7|Robert|King|1992-05-29|80909|Colorado Springs|2|Western
-- 7|Robert|King|1992-05-29|90405|Santa Monica|2|Western
-- 7|Robert|King|1992-05-29|94025|Menlo Park|2|Western
-- 7|Robert|King|1992-05-29|94105|San Francisco|2|Western
-- 7|Robert|King|1992-05-29|95008|Campbell|2|Western
-- 7|Robert|King|1992-05-29|95054|Santa Clara|2|Western
-- 7|Robert|King|1992-05-29|95060|Santa Cruz|2|Western
-- 8|Laura|Callahan|1990-01-09|19428|Philadelphia|3|Northern
-- 8|Laura|Callahan|1990-01-09|44122|Beachwood|3|Northern
-- 8|Laura|Callahan|1990-01-09|45839|Findlay|3|Northern
-- 8|Laura|Callahan|1990-01-09|53404|Racine|3|Northern
-- 9|Anne|Dodsworth|1998-01-27|03049|Hollis|3|Northern
-- 9|Anne|Dodsworth|1998-01-27|03801|Portsmouth|3|Northern
-- 9|Anne|Dodsworth|1998-01-27|48075|Southfield|3|Northern
-- 9|Anne|Dodsworth|1998-01-27|48084|Troy|3|Northern
-- 9|Anne|Dodsworth|1998-01-27|48304|Bloomfield Hills|3|Northern
-- 9|Anne|Dodsworth|1998-01-27|55113|Roseville|3|Northern
-- 9|Anne|Dodsworth|1998-01-27|55439|Minneapolis|3|Northern
