-- 코드를 입력하세요
SELECT i.ingredient_type, sum(h.total_order) from FIRST_HALF h join ICECREAM_INFO i on h.flavor = i.flavor 
group by i.ingredient_type
order by sum(h.total_order) asc