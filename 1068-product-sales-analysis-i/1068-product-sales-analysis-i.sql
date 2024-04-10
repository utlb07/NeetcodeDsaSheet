# Write your MySQL query statement below
select product_name,year,price from Sales s INNER JOIN Product p on s.product_id=p.product_id;
