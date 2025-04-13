<?php
echo "<h2>Multiplication Table (1 to 10)</h2>";
echo "<table border='1'>";

echo "<tr><th>*</th>";
for ($i = 1; $i <= 10; $i++) {
    echo "<th>$i</th>";
}
echo "</tr>";
for ($row = 1; $row <= 10; $row++) {
    echo "<tr>";
    echo "<th>$row</th>"; 
    for ($col = 1; $col <= 10; $col++) {
        echo "<td>" . ($row * $col) . "</td>";
    }
    echo "</tr>";
}
echo "</table>";
?>
