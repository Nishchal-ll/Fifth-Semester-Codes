<!DOCTYPE html>
<html>
<head>
    <title>Student Records</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet">
</head>
<body class="bg-light py-4">
<div class="container">
    <h2 class="text-center mb-4">Student Record List</h2>
    <a href="add.php">
    <button>Add Student</button>
</a>
<br>
<br>
    <?php
    $conn = new mysqli("localhost", "root", "", "crud");
    $result = $conn->query("SELECT * FROM students");
    echo "<table class='table table-bordered table-striped'>
        <thead class='table-primary'>
            <tr>
                <th>Name</th>
                <th>Roll No</th>
                <th>Marks</th>
                <th>Result</th>
                <th>Actions</th>
            </tr>
        </thead>
        <tbody>";

    while ($row = $result->fetch_assoc()) {
        echo "<tr>
            <td>{$row['student_name']}</td>
            <td>{$row['roll_number']}</td>
            <td>{$row['marks_obtained']}</td>
            <td>{$row['result']}</td>
            <td>
                <a href='edit.php?id={$row['std_id']}' class='btn btn-success btn-sm'>Edit</a>
                <a href='delete.php?id={$row['std_id']}' class='btn btn-danger btn-sm'>Delete</a>
            </td>
        </tr>";
    }
    echo "</tbody></table>";


    echo "<h3>Class Stats</h3>";
    $result = $conn->query("SELECT student_name, marks_obtained FROM students ORDER BY marks_obtained DESC LIMIT 1");
    $row = $result->fetch_assoc();
    echo "Topper: " . $row['student_name'] . " (" . $row['marks_obtained'] . " marks)<br>";
    
    $result = $conn->query("SELECT student_name, marks_obtained FROM students ORDER BY marks_obtained ASC LIMIT 1");
    $row = $result->fetch_assoc();
    echo "Lowest: " . $row['student_name'] . " (" . $row['marks_obtained'] . " marks)<br>";
    
    $result = $conn->query("SELECT COUNT(*) AS total FROM students");
    $row = $result->fetch_assoc();
    echo "Total Students: " . $row['total'] . "<br>";
 
    $result = $conn->query("SELECT AVG(marks_obtained) AS average FROM students");
    $row = $result->fetch_assoc();
    echo "Average Marks: " . round($row['average'], 2) . "<br>";
    
    ?>
</div>
</body>
</html>
