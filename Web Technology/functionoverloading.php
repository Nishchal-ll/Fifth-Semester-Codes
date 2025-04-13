<?php
echo"<h1>Function OVERLOADING</h1>";

function add($a, $b, $c = null) {
    if ($c === null) {
        return $a + $b; 
    } else {
        return $a + $b + $c; 
    }
}
echo "Sum of 2 numbers (5 + 10): " . add(5, 10) . "<br>";
echo "Sum of 3 numbers (3 + 6 + 9): " . add(3, 6, 9) . "<br>";


echo "<br>";

?>
