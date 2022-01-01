[![image](https://drive.google.com/uc?export=view&id=1XUQ8wWBIsr7-F8wwCp4S-v0qeOqFfo9y)](https://drive.google.com/drive/folders/1vTvfb3QgLH9VLcvTRkbrA16iWvev8Ic7)

# Lab1 Snapshots (or [Click Here](https://drive.google.com/drive/folders/1vTvfb3QgLH9VLcvTRkbrA16iWvev8Ic7)):

## Contents

* [Lab Objectives](#lab-objectives)
* [Keil Simulation](#keil-simulation)
* [Proteus Simulation and Demo](#proteus-simulation-and-demo)
* [Hardware Demo](#hardware-demo-coming-soon)

---

## Lab Objectives

![image](https://drive.google.com/uc?export=view&id=1OSGsgtugxwyKE-lYXpYIIUfX96XXvjDZ)

* PA1 and PA13 are connected to pull-up and pull-down setups respectively.

* PB1 and PB13 are each connected to and LED and a resistor in active low setup (pin will represent GND when LED is ON).

* It's required to toggle GPIOB1 according to a single-pressing algorithm using GPIOA1 as input.

* It's required to toggle GPIOB13 according to a multi-pressing algoritm using GPIOA13 as input.

> For single pressing, LED is toggled once as long as we are pressing, then we have to release and make another press to toggle the LED again.

> For multi-pressing, LED is toggling continuously as long as we are pressing (of course with a very small delay in between).

---

## Keil Simulation

> Hardware initialization step

[![image](https://drive.google.com/uc?export=view&id=12B6R9ux8XsLgahA9xPrLWFeUJKk-AIsC)](https://drive.google.com/file/d/12B6R9ux8XsLgahA9xPrLWFeUJKk-AIsC/view)

> Button connected to PA1 is pressed

[![image](https://drive.google.com/uc?export=view&id=1dtXQYo05i9in8j_gOKgF4eLPiMFy6ncS)](https://drive.google.com/file/d/1dtXQYo05i9in8j_gOKgF4eLPiMFy6ncS/view)

> Testing the single-pressing algorithm

[![image](https://drive.google.com/uc?export=view&id=1PBADjhqsGqZiIxIQzxs6U9WbP440BSPf)](https://drive.google.com/file/d/1PBADjhqsGqZiIxIQzxs6U9WbP440BSPf/view)

> Releasing the single-pressed button (PA1 becomes high again)

[![image](https://drive.google.com/uc?export=view&id=1IVAGoG1KjlGOefPzq0llNN6IGI1eNY-N)](https://drive.google.com/file/d/1IVAGoG1KjlGOefPzq0llNN6IGI1eNY-N/view)

> What happens after the button connected to PA13 is pressed?

[![image](https://drive.google.com/uc?export=view&id=1rpG_I55mnWsu7A7rld0w-Tiwuf0jw37d)](https://drive.google.com/file/d/1rpG_I55mnWsu7A7rld0w-Tiwuf0jw37d/view)

> Testing the multi-pressing algorithm

[![image](https://drive.google.com/uc?export=view&id=1ZoRdQNcmkmPZBQ55xDMc4awbnOlSx9h0)](https://drive.google.com/file/d/1ZoRdQNcmkmPZBQ55xDMc4awbnOlSx9h0/view)

---

## Proteus Simulation and [Demo](https://youtu.be/4P5zrxG2BYw)

> Schematic Capture

[![image](https://drive.google.com/uc?export=view&id=1OSGsgtugxwyKE-lYXpYIIUfX96XXvjDZ)](https://drive.google.com/file/d/1OSGsgtugxwyKE-lYXpYIIUfX96XXvjDZ/view)

> Program execution and buttons polling

[![image](https://drive.google.com/uc?export=view&id=1Hg9YAYZwL3fSBpPEN7uaj9jl41QZdNbh)](https://drive.google.com/file/d/1Hg9YAYZwL3fSBpPEN7uaj9jl41QZdNbh/view)

> Waiting for a button press

[![image](https://drive.google.com/uc?export=view&id=1HoSnKGFpWQmPPf67j6_tEdGCE7jPxoB3)](https://drive.google.com/file/d/1HoSnKGFpWQmPPf67j6_tEdGCE7jPxoB3/view)

> Button connected to PA1 is pressed and testing the single-pressing algorithm

[![image](https://drive.google.com/uc?export=view&id=1Q-hUbsPZfGhQb7ep-4UfsaGDBzehCBHS)](https://drive.google.com/file/d/1Q-hUbsPZfGhQb7ep-4UfsaGDBzehCBHS/view)

> Releasing the button connected to PA1 (the LED status was not updated till now. I think maybe because the LED takes time to change status and debugging was much faster or maybe it's a bug)

[![image](https://drive.google.com/uc?export=view&id=1IURB42zP4xAA8pnD3ex3T1kufU_o3L2K)](https://drive.google.com/file/d/1IURB42zP4xAA8pnD3ex3T1kufU_o3L2K/view)

> Button connected to PA13 is pressed and testing the multi-pressing algorithm

[![image](https://drive.google.com/uc?export=view&id=1y8pws7-6ZVI3lEyxH7gOG9IOneLlAgBO)](https://drive.google.com/file/d/1y8pws7-6ZVI3lEyxH7gOG9IOneLlAgBO/view)

[![image](https://drive.google.com/uc?export=view&id=1sM1cBO2dZ3jk8_JCPd1EYKlflsoKYhYj)](https://drive.google.com/file/d/1sM1cBO2dZ3jk8_JCPd1EYKlflsoKYhYj/view)

> For a video demo, click [here](https://youtu.be/4P5zrxG2BYw)

---

## Hardware Demo (Coming Soon)

---