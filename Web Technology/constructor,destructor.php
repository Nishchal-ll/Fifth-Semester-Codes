<?php
class Student {
    public $name;
    function __construct($name) {
        $this->name = $name;
        echo "Hello, $name! (Constructor called)<br>";
    }
    function __destruct() {
        echo "Goodbye, $this->name! (Destructor called)<br>";
    }
}
$s1 = new Student("Nishchal");
?>
