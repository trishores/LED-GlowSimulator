/*
*  Copyright 2018-2021 ledmaker.org
*
*  This file is part of Glow Simulator.
*
*  Glow Simulator is free software: you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published
*  by the Free Software Foundation, either version 3 of the License,
*  or any later version.
*
*  Glow Simulator is distributed in the hope that it will be useful, but
*  WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
*  General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with Glow Simulator. If not, see https://www.gnu.org/licenses/.
*/

#include "../../GlowDecompiler/public_api.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#ifdef ELEKTRA_SIM_20

char *htmlString[] = {
"<svg xmlns='http://www.w3.org/2000/svg' version='1.1' width='300px' height='300px' viewBox='-120 -120 240 240' style='background-color:transparent; margin-left:auto; margin-right:auto; display:block;' baseProfile='full'><style>.small {font:1em serif;}</style><circle cx='0' cy='0' r='110' fill='#404040' fill-opacity='1' stroke='#000000' stroke-width='1' stroke-opacity='0.0'/>",
"<g><circle id='led1' cx='-20' cy='15' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='-20' y='15' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.3em'>1</text></g>",
"<g><circle id='led2' cx='-15' cy='-20' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='-15' y='-20' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.3em'>2</text></g>",
"<g><circle id='led3' cx='20' cy='-15' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='20' y='-15' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.3em'>3</text></g>",
"<g><circle id='led4' cx='15' cy='20' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='15' y='20' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.3em'>4</text></g>",
"<g><circle id='led5' cx='49' cy='-49' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='49' y='-49' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.3em'>5</text></g>",
"<g><circle id='led6' cx='70' cy='0' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='70' y='0' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.3em'>6</text></g>",
"<g><circle id='led7' cx='49' cy='49' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='49' y='49' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.3em'>7</text></g>",
"<g><circle id='led8' cx='0' cy='70' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='0' y='70' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.3em'>8</text></g>",
"<g><circle id='led9' cx='-49' cy='49' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='-49' y='49' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.3em'>9</text></g>",
"<g><circle id='led10' cx='-70' cy='0' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='-70' y='0' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.3em'>10</text></g>",
"<g><circle id='led11' cx='-49' cy='-49' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='-49' y='-49' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.3em'>11</text></g>",
"<g><circle id='led12' cx='0' cy='-70' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='0' y='-70' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.3em'>12</text></g>",
"<g><circle id='led13' cx='36' cy='-88' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='36' y='-88' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.3em'>13</text></g>",
"<g><circle id='led14' cx='88' cy='-36' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='88' y='-36' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.3em'>14</text></g>",
"<g><circle id='led15' cx='88' cy='36' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='88' y='36' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.3em'>15</text></g>",
"<g><circle id='led16' cx='36' cy='88' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='36' y='88' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.3em'>16</text></g>",
"<g><circle id='led17' cx='-36' cy='88' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='-36' y='88' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.3em'>17</text></g>",
"<g><circle id='led18' cx='-88' cy='36' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='-88' y='36' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.3em'>18</text></g>",
"<g><circle id='led19' cx='-88' cy='-36' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='-88' y='-36' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.3em'>19</text></g>",
"<g><circle id='led20' cx='-36' cy='-88' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='-36' y='-88' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.3em'>20</text></g>",
"</svg>",
};

#endif