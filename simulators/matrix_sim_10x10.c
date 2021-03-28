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

#ifdef MATRIX_SIM_10x10

char *htmlString[] = {
"<svg xmlns='http://www.w3.org/2000/svg' version='1.1' width='300px' height='300px' viewBox='5 5 290 290' style='background-color:transparent; margin-left:auto; margin-right:auto; display:block;' baseProfile='full'><style>.small {font:0.9em serif;}</style><rect x='0' y='0' width='300' height='300' fill='#404040' fill-opacity='1' stroke='#000000' stroke-width='1' stroke-opacity='1.0'/>\n",
"<g><circle id='led1' cx='27' cy='27' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='27' y='27' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>1</text></g>\n",
"<g><circle id='led2' cx='54' cy='27' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='54' y='27' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>2</text></g>\n",
"<g><circle id='led3' cx='81' cy='27' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='81' y='27' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>3</text></g>\n",
"<g><circle id='led4' cx='109' cy='27' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='109' y='27' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>4</text></g>\n",
"<g><circle id='led5' cx='136' cy='27' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='136' y='27' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>5</text></g>\n",
"<g><circle id='led6' cx='163' cy='27' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='163' y='27' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>6</text></g>\n",
"<g><circle id='led7' cx='190' cy='27' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='190' y='27' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>7</text></g>\n",
"<g><circle id='led8' cx='218' cy='27' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='218' y='27' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>8</text></g>\n",
"<g><circle id='led9' cx='245' cy='27' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='245' y='27' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>9</text></g>\n",
"<g><circle id='led10' cx='272' cy='27' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='272' y='27' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>10</text></g>\n",
"<g><circle id='led11' cx='27' cy='54' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='27' y='54' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>11</text></g>\n",
"<g><circle id='led12' cx='54' cy='54' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='54' y='54' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>12</text></g>\n",
"<g><circle id='led13' cx='81' cy='54' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='81' y='54' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>13</text></g>\n",
"<g><circle id='led14' cx='109' cy='54' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='109' y='54' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>14</text></g>\n",
"<g><circle id='led15' cx='136' cy='54' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='136' y='54' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>15</text></g>\n",
"<g><circle id='led16' cx='163' cy='54' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='163' y='54' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>16</text></g>\n",
"<g><circle id='led17' cx='190' cy='54' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='190' y='54' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>17</text></g>\n",
"<g><circle id='led18' cx='218' cy='54' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='218' y='54' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>18</text></g>\n",
"<g><circle id='led19' cx='245' cy='54' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='245' y='54' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>19</text></g>\n",
"<g><circle id='led20' cx='272' cy='54' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='272' y='54' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>20</text></g>\n",
"<g><circle id='led21' cx='27' cy='81' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='27' y='81' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>21</text></g>\n",
"<g><circle id='led22' cx='54' cy='81' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='54' y='81' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>22</text></g>\n",
"<g><circle id='led23' cx='81' cy='81' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='81' y='81' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>23</text></g>\n",
"<g><circle id='led24' cx='109' cy='81' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='109' y='81' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>24</text></g>\n",
"<g><circle id='led25' cx='136' cy='81' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='136' y='81' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>25</text></g>\n",
"<g><circle id='led26' cx='163' cy='81' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='163' y='81' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>26</text></g>\n",
"<g><circle id='led27' cx='190' cy='81' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='190' y='81' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>27</text></g>\n",
"<g><circle id='led28' cx='218' cy='81' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='218' y='81' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>28</text></g>\n",
"<g><circle id='led29' cx='245' cy='81' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='245' y='81' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>29</text></g>\n",
"<g><circle id='led30' cx='272' cy='81' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='272' y='81' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>30</text></g>\n",
"<g><circle id='led31' cx='27' cy='109' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='27' y='109' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>31</text></g>\n",
"<g><circle id='led32' cx='54' cy='109' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='54' y='109' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>32</text></g>\n",
"<g><circle id='led33' cx='81' cy='109' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='81' y='109' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>33</text></g>\n",
"<g><circle id='led34' cx='109' cy='109' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='109' y='109' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>34</text></g>\n",
"<g><circle id='led35' cx='136' cy='109' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='136' y='109' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>35</text></g>\n",
"<g><circle id='led36' cx='163' cy='109' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='163' y='109' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>36</text></g>\n",
"<g><circle id='led37' cx='190' cy='109' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='190' y='109' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>37</text></g>\n",
"<g><circle id='led38' cx='218' cy='109' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='218' y='109' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>38</text></g>\n",
"<g><circle id='led39' cx='245' cy='109' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='245' y='109' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>39</text></g>\n",
"<g><circle id='led40' cx='272' cy='109' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='272' y='109' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>40</text></g>\n",
"<g><circle id='led41' cx='27' cy='136' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='27' y='136' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>41</text></g>\n",
"<g><circle id='led42' cx='54' cy='136' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='54' y='136' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>42</text></g>\n",
"<g><circle id='led43' cx='81' cy='136' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='81' y='136' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>43</text></g>\n",
"<g><circle id='led44' cx='109' cy='136' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='109' y='136' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>44</text></g>\n",
"<g><circle id='led45' cx='136' cy='136' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='136' y='136' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>45</text></g>\n",
"<g><circle id='led46' cx='163' cy='136' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='163' y='136' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>46</text></g>\n",
"<g><circle id='led47' cx='190' cy='136' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='190' y='136' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>47</text></g>\n",
"<g><circle id='led48' cx='218' cy='136' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='218' y='136' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>48</text></g>\n",
"<g><circle id='led49' cx='245' cy='136' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='245' y='136' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>49</text></g>\n",
"<g><circle id='led50' cx='272' cy='136' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='272' y='136' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>50</text></g>\n",
"<g><circle id='led51' cx='27' cy='163' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='27' y='163' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>51</text></g>\n",
"<g><circle id='led52' cx='54' cy='163' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='54' y='163' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>52</text></g>\n",
"<g><circle id='led53' cx='81' cy='163' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='81' y='163' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>53</text></g>\n",
"<g><circle id='led54' cx='109' cy='163' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='109' y='163' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>54</text></g>\n",
"<g><circle id='led55' cx='136' cy='163' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='136' y='163' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>55</text></g>\n",
"<g><circle id='led56' cx='163' cy='163' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='163' y='163' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>56</text></g>\n",
"<g><circle id='led57' cx='190' cy='163' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='190' y='163' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>57</text></g>\n",
"<g><circle id='led58' cx='218' cy='163' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='218' y='163' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>58</text></g>\n",
"<g><circle id='led59' cx='245' cy='163' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='245' y='163' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>59</text></g>\n",
"<g><circle id='led60' cx='272' cy='163' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='272' y='163' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>60</text></g>\n",
"<g><circle id='led61' cx='27' cy='190' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='27' y='190' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>61</text></g>\n",
"<g><circle id='led62' cx='54' cy='190' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='54' y='190' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>62</text></g>\n",
"<g><circle id='led63' cx='81' cy='190' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='81' y='190' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>63</text></g>\n",
"<g><circle id='led64' cx='109' cy='190' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='109' y='190' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>64</text></g>\n",
"<g><circle id='led65' cx='136' cy='190' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='136' y='190' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>65</text></g>\n",
"<g><circle id='led66' cx='163' cy='190' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='163' y='190' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>66</text></g>\n",
"<g><circle id='led67' cx='190' cy='190' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='190' y='190' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>67</text></g>\n",
"<g><circle id='led68' cx='218' cy='190' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='218' y='190' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>68</text></g>\n",
"<g><circle id='led69' cx='245' cy='190' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='245' y='190' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>69</text></g>\n",
"<g><circle id='led70' cx='272' cy='190' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='272' y='190' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>70</text></g>\n",
"<g><circle id='led71' cx='27' cy='218' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='27' y='218' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>71</text></g>\n",
"<g><circle id='led72' cx='54' cy='218' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='54' y='218' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>72</text></g>\n",
"<g><circle id='led73' cx='81' cy='218' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='81' y='218' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>73</text></g>\n",
"<g><circle id='led74' cx='109' cy='218' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='109' y='218' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>74</text></g>\n",
"<g><circle id='led75' cx='136' cy='218' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='136' y='218' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>75</text></g>\n",
"<g><circle id='led76' cx='163' cy='218' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='163' y='218' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>76</text></g>\n",
"<g><circle id='led77' cx='190' cy='218' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='190' y='218' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>77</text></g>\n",
"<g><circle id='led78' cx='218' cy='218' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='218' y='218' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>78</text></g>\n",
"<g><circle id='led79' cx='245' cy='218' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='245' y='218' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>79</text></g>\n",
"<g><circle id='led80' cx='272' cy='218' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='272' y='218' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>80</text></g>\n",
"<g><circle id='led81' cx='27' cy='245' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='27' y='245' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>81</text></g>\n",
"<g><circle id='led82' cx='54' cy='245' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='54' y='245' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>82</text></g>\n",
"<g><circle id='led83' cx='81' cy='245' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='81' y='245' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>83</text></g>\n",
"<g><circle id='led84' cx='109' cy='245' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='109' y='245' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>84</text></g>\n",
"<g><circle id='led85' cx='136' cy='245' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='136' y='245' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>85</text></g>\n",
"<g><circle id='led86' cx='163' cy='245' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='163' y='245' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>86</text></g>\n",
"<g><circle id='led87' cx='190' cy='245' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='190' y='245' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>87</text></g>\n",
"<g><circle id='led88' cx='218' cy='245' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='218' y='245' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>88</text></g>\n",
"<g><circle id='led89' cx='245' cy='245' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='245' y='245' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>89</text></g>\n",
"<g><circle id='led90' cx='272' cy='245' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='272' y='245' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>90</text></g>\n",
"<g><circle id='led91' cx='27' cy='272' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='27' y='272' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>91</text></g>\n",
"<g><circle id='led92' cx='54' cy='272' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='54' y='272' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>92</text></g>\n",
"<g><circle id='led93' cx='81' cy='272' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='81' y='272' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>93</text></g>\n",
"<g><circle id='led94' cx='109' cy='272' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='109' y='272' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>94</text></g>\n",
"<g><circle id='led95' cx='136' cy='272' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='136' y='272' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>95</text></g>\n",
"<g><circle id='led96' cx='163' cy='272' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='163' y='272' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>96</text></g>\n",
"<g><circle id='led97' cx='190' cy='272' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='190' y='272' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>97</text></g>\n",
"<g><circle id='led98' cx='218' cy='272' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='218' y='272' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>98</text></g>\n",
"<g><circle id='led99' cx='245' cy='272' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='245' y='272' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>99</text></g>\n",
"<g><circle id='led100' cx='272' cy='272' r='12' fill='#%02x%02x%02x' fill-opacity='%3.2f' stroke='#000000' stroke-width='1' stroke-opacity='0.3'/><text class='small' x='272' y='272' text-anchor='middle' stroke='#000000' stroke-width='1' stroke-opacity='0.01' dy='.4em'>100</text></g>\n",
"</svg>\n"
};

#endif