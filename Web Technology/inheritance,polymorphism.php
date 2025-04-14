<?php
class Lecturer {
    public $name;
    public $subject;
    function __construct($name, $subject) {
        $this->name = $name;
        $this->subject = $subject;
    }
    function displayInfo() {
        echo "Lecturer: $this->name teaches $this->subject<br>";
    }
}
class Parttime extends Lecturer {
    public $hours;
    function __construct($name, $subject, $hours) {
        parent::__construct($name, $subject); 
        $this->hours = $hours;
    }
    function displayInfo() {
        echo "Part-time Lecturer: $this->name teaches $this->subject for $this->hours hours/week<br>";
    }
}
class Fulltime extends Lecturer {
    public $salary;

    function __construct($name, $subject, $salary) {
        parent::__construct($name, $subject); 
        $this->salary = $salary;
    }
    function displayInfo() {
        echo "Full-time Lecturer: $this->name teaches $this->subject with salary $this->salary<br>";
    }
}
$pt = new Parttime("Nishchal", "Web Technology", 10);
$ft = new Fulltime("Ram", "Kaji", 50000);
$pt->displayInfo();
$ft->displayInfo();
?>
