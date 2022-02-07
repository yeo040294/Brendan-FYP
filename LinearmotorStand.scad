// radius of the circle of balls (average between external and internal radiuses)


//ball bearing stand
//stand();

// linear motor stand
linear_motor();


// test cylinder
/*
translate([1,0,1])
rotate([90,90,0])
cylinder(2,d=2);*/

module stand() {
difference()
{
    stand_width = 20;
    stand_height = 57.4;
    base_width = 40;
    base_height = 3;
    union() {
            
       
	/*
          translate([-thickness,+7*support_length-thickness,-support_height])
          cube([2*support_length,2*support_length,support_height+support_height+2*thickness]);
    }
        */
        //stand
    translate([base_width/4, base_width/4,0])   
    cube([stand_width,stand_width,stand_height]);
    
        //base
        
    cube([base_width, base_width, base_height]);
        
        
        }
        
        // hold for middle screw
        translate([base_width/2,base_width/2,stand_height-30])
       cylinder(50,d=4);
    //hold for screw
        translate([7*base_width/8,7*base_width/8,-base_height])
       cylinder(10,d=4);
        translate([1*base_width/8,7*base_width/8,-base_height])
       cylinder(10,d=4);
       translate([1*base_width/8,1*base_width/8,-base_height])
       cylinder(10,d=4);
       translate([7*base_width/8,1*base_width/8,-base_height])
       cylinder(10,d=4);
    
}
}

module linear_motor() {
    base_width = 40;
    base_height = 3;
    thickness = 3;
    motor_width = 22.5;
    motor_depth = 25.5;
    motor_height = 27;
    linear_height = 51.5;  //default 52.5
    
    back_piston_deep = 8.5+10;
    back_piston_width = 10;
    
    padded_width = motor_width+thickness;
    padded_depth = motor_depth+thickness;
    
    difference() {
        union() {
            
            // base
            cube([base_width, base_width, base_height]);
            
            // linear motor base
            translate([(base_width-padded_width)/2,(base_width-padded_depth)/2,0])
            cube([padded_width,padded_depth,linear_height]);
            
            // holder
            translate([(base_width-padded_width)/2,(base_width-padded_depth)/2,linear_height])
            cube([padded_width,thickness,motor_height]);
            
            translate([(base_width-padded_width)/2,(base_width-padded_depth)/2,linear_height])
            cube([thickness,padded_depth,motor_height]);
            
            translate([(base_width-padded_width)/2,(base_width-padded_depth)/2+motor_depth,linear_height])
            cube([padded_width,thickness,motor_height]);
            
            translate([(base_width-padded_width)/2+motor_width,(base_width-padded_depth)/2,linear_height])
            cube([thickness,padded_depth,motor_height]);
        }
        
        // screws
        translate([7*base_width/8,7*base_width/8,-base_height])
            cylinder(10,d=4);
        translate([1*base_width/8,7*base_width/8,-base_height])
            cylinder(10,d=4);
       translate([1*base_width/8,1*base_width/8,-base_height])
            cylinder(10,d=4);
       translate([7*base_width/8,1*base_width/8,-base_height])
            cylinder(10,d=4);
        
        // hole for piston back
        translate([base_width/2,base_width/2,linear_height-back_piston_deep])
            cylinder(back_piston_deep, d=back_piston_width);
        
        // screw holes linear motor
        translate([(base_width-padded_width)/2+5+1,(base_width-padded_depth)/2+thickness,linear_height+19.5+1])
        rotate([90,90,0])
            cylinder(thickness,d=2);
        
        translate([(base_width-padded_width)/2+17+1,(base_width-padded_depth)/2+thickness,linear_height+4.5+1])
        rotate([90,90,0])
            cylinder(thickness,d=2);
            
        // hole 
        translate([(base_width-padded_width)/2+motor_width,(base_width-7)/2,linear_height])
            cube([thickness,7,7]);
    }
}
