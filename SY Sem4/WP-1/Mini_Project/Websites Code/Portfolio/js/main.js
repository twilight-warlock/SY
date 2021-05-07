$(document).ready(function () {

    //  Preloader
    setTimeout(function(){
        $('.cover').addClass('hide');
        $('.header_area').removeClass('hide')
        $('.site-main').removeClass('hide')
        $('.footer-area').removeClass('hide')
    }, 3000);

    // Projects

    let $btns = $('.project-area .button-group button');

    $btns.click(function (e) {

        $('.project-area .button-group button').removeClass('active');
        e.target.classList.add('active');

        let selector = $(e.target).attr('data-filter');
        $('.project-area .grid').isotope({
            filter: selector
        });

        return false;
    })

    $('.project-area .button-group #btn1').trigger('click');

    $('.project-area .grid .test-popup-link').magnificPopup({
        type: 'image',
        gallery: { enabled: true }
    });

    // Owl-carousel

    $('.site-main .about-area .owl-carousel').owlCarousel({
        loop: true,
        autoplay: true,
        dots: true,
        responsive: {
            0: {
                items: 1
            },
            560: {
                items: 2
            }
        }
    })

});

document.querySelector("#subscribe").addEventListener("submit",(e)=>{
    e.preventDefault()
    var x = document.getElementById("txtnum").value;
    var y = document.getElementById("txtemail").value;
    var mailformat = /^w+([.-]?w+)*@w+([.-]?w+)*(.w{2,3})+$/;
  

  // If x is Not a Number or less than or greater than 10 digits
  if (isNaN(x) || x < 1000000000 || x > 9999999999) {
    alert("Number not valid");
  } else if (y.match(mailformat)){  
    alert("Please enter a valid e-mail address");  
    }   
  else {
    alert("mailed");
  }
    
})