CREATE TYPE PointType AS( 
x int, y int 
); 

CREATE TYPE LineType AS( 
	end1 PointType, 
	end2 PointType 
); 

CREATE TABLE Lines( 
	lineid int PRIMARY KEY, 
	line LineType, 
	dist float 
); 

CREATE FUNCTION distance(x1 integer,y1 integer,x2 integer,y2 integer) 
RETURNS float AS $$ 
BEGIN 
RETURN sqrt(power((x2-x1),2)+power((y2-y1),2)); 
END; 
$$ LANGUAGE plpgsql; 

INSERT INTO Lines Values(1,((0,0),(5,5)),distance(0,0,5,5)),(2,((4,5),(7,8)),distance(4,5,7,8)), 
(3,((6,2),(8,6)),distance(6,2,8,6)); 

SELECT * FROM Lines; 

SELECT lineid,((Lines.line).end1) ,((Lines.line).end2) FROM Lines;

DROP Table Lines; 
DROP TYPE LineType; 
DROP TYPE PointType; 



