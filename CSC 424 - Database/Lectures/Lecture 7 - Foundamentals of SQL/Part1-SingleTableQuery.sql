use premiere;

select customer_num, customer_name, balance
from customer;

select * from part;

select customer_num from customer 
where customer_num = '148';

-- unique to MySQL
select customer_num from customer 
where customer_num = "148";

select customer_num, customer_name, balance, credit_limit
from customer
where balance > credit_limit;

select description from part
where warehouse = '3' and on_hand > 25;

select * from part;

select description from part
where warehouse = '3' or on_hand > 25;

select description from part
where not warehouse = 3;

select customer_num, customer_name, balance
from customer
where balance >= 2000 and balance <= 5000; 

select customer_num, customer_name, balance
from customer
where balance between 2000 and 5000; 

-- computing values
select customer_num, customer_name, (credit_limit - balance)
from customer;

select customer_num, customer_name, (credit_limit - balance) as available_credit
from customer;

-- using Like operator
select customer_num, customer_name, credit_limit from customer
where customer_name like '%John%';

select customer_num, customer_name, credit_limit from customer
where customer_num like '6__';

-- using IN operator
select customer_num, customer_name, credit_limit from customer
where credit_limit in (5000, 10000, 15000);

-- Sort
select customer_num, customer_name, credit_limit from customer
order by credit_limit desc, customer_name;

-- Using functions
select count(*) as HW_Count from part where class = 'HW';

select sum(balance), avg(balance), max(balance), min(balance) from customer;

select customer_num from orders;

select distinct customer_num from orders;

-- sub queries
select order_num from order_line
where part_num in 
(select part_num from part where class = 'AP');

select customer_num, customer_name, balance
from customer 
where balance > (select avg(balance) from customer);

-- Group by
select rep_num, avg(balance) from customer
group by rep_num
order by rep_num;

select rep_num, avg(balance) from customer
order by rep_num
group by rep_num;     //wrong way

-- Having
select rep_num, avg(balance) from customer
group by rep_num
having count(*) < 4
order by rep_num;

select credit_limit, count(*) from customer
where rep_num = '20'
group by credit_limit
having count(*) > 1;

-- NULL values
select customer_num, customer_name, street from customer
where street is null;