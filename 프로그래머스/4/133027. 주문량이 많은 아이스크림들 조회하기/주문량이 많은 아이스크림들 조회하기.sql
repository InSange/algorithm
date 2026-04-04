-- 1단계: 상반기와 7월 데이터를 위아래로 찰싹 이어 붙인 '임시 테이블'을 만듭니다.
WITH CombinedSales AS (
    SELECT FLAVOR, TOTAL_ORDER FROM FIRST_HALF
    UNION ALL
    SELECT FLAVOR, TOTAL_ORDER FROM JULY
)

-- 2단계: 합쳐진 데이터에서 맛별로 주문량을 싹 다 더하고 순위를 매깁니다.
SELECT FLAVOR
FROM CombinedSales
GROUP BY FLAVOR
ORDER BY SUM(TOTAL_ORDER) DESC
LIMIT 3;