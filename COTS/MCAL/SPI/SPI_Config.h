#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H


/*Mode of operation Options: MASTER , SLAVE */
#define SPI_MODE    MASTER

/*Speed options: NORMAL_SPEED , DOUBLE_SPEED */
#define SPI_SPEED   NORMAL_SPEED

/*Clock Rate options*/

//for normal speed
/* SCK_4 , SCK_16 , SCK_64, SCK_128 */

//for double speed
/* SCK_2 , SCK_8 , SCK_32, SCK_64 */

#define SPI_SCK   SCK_16


#endif

