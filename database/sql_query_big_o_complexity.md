# I've recently learned that SQL queries also have time complexity, which was not covered in my university.

## Here's what I've learned, below are the time complexity from best to worst:

1. O(1) - Constant Time Complexity: The query's execution time is constant, regardless of the size of the data. It performs the same number of operations regardless of the data size.

SQL queries example: `SELECT * FROM table WHERE id = 333;`

Explanation: **In this query, the database directly access the table record with ID 333, no matter how many data exists in the database. The execution time remains constant.**

2. O(log n) - Logarithmic Time Complexity: The query's execution time increases logarithmically with the size of the data. As the data grows, the execution time increases, but at a slower rate compared to linear growth.

SQL queries example: `SELECT * FROM sorted_table WHERE id = 111;`

Explanation: Queries with O(log n) complexity are often associated with operations that utilize binary search or divide-and-conquer techniques. These queries reduce the data size to half with each operation, resulting in faster performance for large datasets compared to linear time complexity. The logarithmic growth ensures that the execution time increases at a much slower rate as the data size grows. **If the 'sorted_table' is sorted by 'id', the query can efficiently perform a binary search to find the record with ID 111, reducing the search space in each iteration.**

3. O(n) - Linear Time Complexity: The query's execution time increases linearly with the size of the data. The time taken is directly proportional to the number of data elements.

SQL queries example: `SELECT * FROM customers WHERE age = 21;`

Explanation: **This query retrieves all customer records with an age of 21. The time taken will increase linearly with the number of customers with an age of 21.**

4. O(n log n) - Linearithmic Time Complexity: The query's execution time increases at a rate between linear and logarithmic. Common in sorting and searching algorithms like merge sort and quicksort.

SQL queries example: `SELECT * FROM products ORDER BY price;`

Explanation: Queries with O(n log n) complexity are often found in sorting and searching operations that use efficient algorithms such as merge sort or quicksort. These algorithms divide the data into smaller subsets, sort or search within those subsets, and then combine them back. The time complexity grows at a slower rate than quadratic, making these queries more efficient for large datasets compared to purely quadratic operations. **In MySQL, the ORDER BY clause is used to sort the result set of a query based on specified columns. The algorithm used for ORDER BY can vary depending on the version of MySQL but it typically uses quicksort algorithms.**

5. O(n^2) - Quadratic Time Complexity: The query's execution time increases quadratically with the size of the data. The time taken is directly proportional to the square of the number of data elements.

SQL queries example: `SELECT * FROM employees e1, employees e2 WHERE e1.department_id = e2.department_id;`

Explanation: Queries with O(n^2) complexity often involve nested loops or operations that require comparing each element with every other element in the dataset. The execution time grows exponentially with the data size, making these queries highly inefficient for large datasets. **This query performs a self-join on the 'employees' table based on the 'department_id' column. It compares each employee with all other employees in the same department, resulting in quadratic time complexity.**

6. O(n^k) - Polynomial Time Complexity: The query's execution time increases as a polynomial function of the data size, where "k" is a constant exponent.

SQL queries example: `SELECT * FROM orders o1, orders o2, orders o3 WHERE o1.customer_id = o2.customer_id AND o2.customer_id = o3.customer_id;`

Explanation: Queries with O(n^k) complexity have time complexities that grow as polynomial functions of the data size. The value of "k" determines the rate of growth. For example, O(n^3) signifies cubic growth, O(n^4) signifies quartic growth, and so on. These queries are less efficient than linear or logarithmic queries and become impractical for moderately large datasets. **This query performs a self-join on the 'orders' table three times, based on the 'customer_id' column. The time complexity is O(n^3) since it involves three nested loops.**

## Conclusion:

Knowing of SQL query big O complexity makes me think about how to improve the queries and how to avoid worst-case scenarios, you can follow some best practices and optimization techniques but here are some tips to make SQL queries more efficient, ACCORDING TO MY RESEARCH, CMIIW:

1. Use Indexes: Properly index the columns that are frequently used in search conditions, join clauses, and sorting. **Indexing helps reduce the number of rows that need to be scanned, leading to faster query execution.**

2. Limit the Result Set: **Only retrieve the columns that you need in the result set**, rather than using SELECT * to fetch all columns. This reduces the amount of data transferred and processed.

3. Avoid SELECT DISTINCT: Using **SELECT DISTINCT can be computationally expensive. If possible, use GROUP BY to achieve the desired results instead.**

4. Be Mindful of Joins: **Limit the number of joins**, especially in cases where the number of joined rows can explode exponentially. Optimize join conditions and **consider using INNER JOIN when possible**. Why should you consider using INNER JOIN? Well, **using INNER JOIN when possible is often recommended because it returns only the matching rows between the two tables involved in the join. Other types of joins, like OUTER JOINs (LEFT JOIN, RIGHT JOIN, and FULL JOIN), can return additional rows with NULL values, which might not be needed in certain situations.**

5. Use WHERE Clause Effectively: **Place filtering conditions in the WHERE clause to limit the number of rows returned**. This reduces the data that needs to be processed.

6. Utilize Aggregate Functions: **Use aggregate functions** like COUNT, SUM, AVG, etc; instead of retrieving individual records and performing calculations in the application code.

7. Avoid Using Subqueries Unnecessarily: **Subqueries can be powerful but may have performance implications**. Consider using JOINs and other optimization techniques instead.

8. Optimize ORDER BY: **Minimize the use of ORDER BY, especially on large result sets**. If ordering is required, try to sort based on indexed columns.

9. Consider Caching: **For frequently executed queries, consider caching the results** to avoid unnecessary database hits.

10. Regularly Maintain the Database: **Perform regular database maintenance** tasks, such as updating statistics and rebuilding indexes, to keep the database performance optimal.

11. Partitioning: If dealing with large tables, **consider partitioning data to reduce the amount of data accessed during queries.**

Example of Partitioning in a Query:

Let's consider a simplified example where we have a large 'sales' table with millions of records, and we want to retrieve sales data for a specific year. With partitioning, the 'sales' table can be partitioned based on the 'year' column. Each partition would contain sales data for a specific year.

Without partitioning: `SELECT * FROM sales WHERE year = 2023;`

In this case, the database engine would have to scan the entire 'sales' table, even if most of the data is from other years, resulting in a slower query.

With partitioning: `SELECT * FROM sales_partition_2023;`

In this example, the 'sales' table has been partitioned into separate partitions for each year (e.g., 'sales_partition_2023', 'sales_partition_2022', etc.). The query now accesses the specific partition containing data for the year 2023 directly. This approach is much faster and more efficient, especially when dealing with large datasets.

Partitioning is a powerful optimization technique, but its effectiveness depends on the nature of the data and the specific queries being executed. Proper analysis, planning, and understanding of the data access patterns are essential when deciding whether to implement partitioning in a database.

You might ask something like I was, "So if I decide to make a partition to the table, I have to migrate the data from sales table to new table which is sales_partition_2023 and delete the entire 2023 sales data on sales table?" Yes, that's correct. 

**When you implement table partitioning, you typically need to perform the following steps:**

- **Create the Partitioned Table:** You create a new table, let's say 'sales_partition_2023', with the same structure as the original 'sales' table. However, the new table will be partitioned based on the 'year' column.

- **Migrate Data:** You migrate the data for the year 2023 from the original 'sales' table to the new 'sales_partition_2023' table. This involves inserting the relevant records into the appropriate partition based on the 'year' column.

- **Backup the Original Table Data:** This is very important! As you might need it in the future but you already deleted it, what are you gonna do? get the point? ok, let's move on.

- **Delete Data from the Original Table:** After successfully migrating the data to the new partitioned table, you can delete the data for the year 2023 from the original 'sales' table. Since the data now resides in the appropriate partition, it is safe to remove it from the original table.

By following these steps, you'll have effectively partitioned the 'sales' table based on the 'year' column. Queries that target specific years, like SELECT * FROM sales WHERE year = 2023;, can then take advantage of the partitioning. The database engine will automatically access the appropriate partition for the given year, making the query faster and more efficient.
 
12. Avoid Wildcard Searches: Avoid leading wildcard searches (e.g., WHERE name LIKE '%XYZ%'), as they may not effectively use indexes. **As the dataset grows, the time required to scan the entire table for potential matches increases significantly, leading to a slowdown in query performance.**

By following these best practices and being mindful of query complexity, you can optimize SQL queries and improve their efficiency, leading to better database performance. **Always test the queries with different data sizes and profile the performance to ensure they meet your performance requirements.**

Additional References:

- https://www.datacamp.com/tutorial/sql-tutorial-query

- https://www.kdnuggets.com/2017/08/write-better-sql-queries-definitive-guide-part-2.html/2
