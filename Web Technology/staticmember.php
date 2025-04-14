<?php
class Student {
    public static $count = 0;
    function __construct() {
        self::$count++;
    }
}
$s1 = new Student();
$s2 = new Student();
$s3 = new Student();
echo "Total Students: " . Student::$count;
echo "<br>";
?>
