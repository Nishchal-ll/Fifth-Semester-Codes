<?php
class Lecturer {
    private $name;       
    protected $subject;    
    public $type;          

    function __construct($name, $subject, $type) {
        $this->name = $name;
        $this->subject = $subject;
        $this->type = $type;
    }

    public function getName() {
        return $this->name;
    }

    public function setName($newName) {
        $this->name = $newName;
    }

    public function displayInfo() {
        echo "$this->type Lecturer: " . $this->getName() . " teaches " . $this->subject . "<br>";
    }
}
class Parttime extends Lecturer {
    private $hours;

    function __construct($name, $subject, $hours) {
        parent::__construct($name, $subject, "Part-time");
        $this->hours = $hours;
    }

    public function displayInfo() {
        echo "Part-time Lecturer: " . $this->getName() . " teaches $this->subject for $this->hours hours/week<br>";
    }
}

class Fulltime extends Lecturer {
    private $salary;

    function __construct($name, $subject, $salary) {
        parent::__construct($name, $subject, "Full-time");
        $this->salary = $salary;
    }

    public function displayInfo() {
        echo "Full-time Lecturer: " . $this->getName() . " teaches $this->subject with salary $this->salary<br>";
    }
}

$pt = new Parttime("Nishchal", "Cryptograph", 10);
$ft = new Fulltime("Ram", "Physics", 50000);

$pt->displayInfo();
$ft->displayInfo();

$pt->setName("Mr. Acharya");
$pt->displayInfo();
?>
