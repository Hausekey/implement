function Person(first, last){
	this.firstName = first;
	this.lastName = last;
}

Person.prototype.getInitials = function(){
	return this.firstName.charAt(0) + this.lastName.charAt(0);
}

Person.checkName = function(n){

}

var pers1 = new Person("Tom","Smith");
