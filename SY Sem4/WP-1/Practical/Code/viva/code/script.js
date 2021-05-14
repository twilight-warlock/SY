document.querySelector("form").addEventListener("submit",(e)=>{
    e.preventDefault()
    const userName = document.getElementById("fname").value
    const date = document.getElementById("date").value
    const phone = document.getElementById("phone").value
    let age = 0;

    if(userName==""){
        alert("Name required")
    }else if(date==""){
        alert("Date required")
    }
    else if(phone==""){
        alert("Phone number is required")
    }
    else if (isNaN(phone) || phone < 1000000000 || phone > 9999999999) {
        alert("Number not valid");
    } 
    else{
        age = calculateAge(date)
        alert("Succesfully registered! \n Your name is : "+userName+ "\n Your number is : "+phone+ "\n Your age is : "+age)
    }
})

function calculateAge(dob) { 
    var today = new Date();
    var birthDate = new Date(dob);
    var age = today.getFullYear() - birthDate.getFullYear();
    var month = today.getMonth() - birthDate.getMonth();
    if (month < 0 || (month === 0 && today.getDate() < birthDate.getDate())) {
        age--;
    }
    return age;
}