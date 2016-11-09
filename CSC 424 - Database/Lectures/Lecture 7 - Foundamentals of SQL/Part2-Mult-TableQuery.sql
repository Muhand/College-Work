select customer_num, customer_name, rep.rep_num, last_name, first_name
from customer, rep
where customer.rep_num = rep.rep_num
order by rep.rep_num;

select customer_num, customer_name, rep.rep_num, last_name, first_name
from customer, rep
where customer.rep_num = rep.rep_num and credit_limit = 7500;

select order_num, o.part_num, description, num_ordered, quoted_price, price
from order_line as o, part as p
where o.part_num = p.part_num;

select description from order_line as o, part as p
where o.part_num = p.part_num and order_num = '21610';

select description from part 
where part_num in (select part_num from order_line where order_num = '21610');

select order_num, order_date from orders
where order_num in
	(select order_num from order_line where part_num = 'DR93');
    
select order_num, order_date from orders
where exists 
	(select * from order_line
		where orders.order_num = order_line.order_num and part_num = 'DR93');
     
select order_num, order_date from orders
where order_num in
	(select order_num from order_line
		where part_num in
			(select part_num from part where warehouse = '3') );


    
    